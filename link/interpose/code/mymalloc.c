#ifdef COMPILETIME
#include <stdio.h>
#include <stdlib.h>

void *mymalloc(size_t size) {
    void *ptr = malloc(size);
    printf("malloc(%d) = %p\n",(int) size, ptr);
    return ptr;
}

void myfree(void *ptr) {
    free(ptr);
    printf("free(%p)\n",ptr);
}

#endif

#ifdef LINKTIME
#include <stdio.h>
#include <stdlib.h>

 void *__real_malloc(size_t size);
 void __real_free(void *ptr);

/* malloc wrapper function */
void *__wrap_malloc(size_t size) {
    void *ptr =__real_malloc(size);
    printf("malloc(%d) = %p\n",(int) size, ptr);
    return ptr;
}

/* free wrapper function */
void __wrap_free(void *ptr) {
    __real_free(ptr);
    printf("free(%p)\n",ptr);
}

#endif

#ifdef RUNTIME
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
/* wrapper function of malloc*/
void *malloc(size_t size) {
    static __thread int print_times = 0;
    print_times++;

    // pointer of libc malloc
    void *(*mallocp)(size_t size);
    char *error;
    //get addr of libc malloc
    mallocp = dlsym(RTLD_NEXT,"malloc");
    if((error = dlerror()) != NULL) {
        fputs(error,stderr);
        exit(1);
    }
    // call libc malloc
    char* ptr= mallocp(size);
    if(print_times == 1) printf("malloc(%d) = %p\n", (int)size, ptr);
    print_times = 0;
    return ptr;
}
/* wrapper function of free */
void free(void* ptr) {
    static __thread int print_times = 0;
    print_times++;

    void(*freep)(void *) = NULL;
    char* error;

    if(!ptr) return;

    freep = dlsym(RTLD_NEXT,"free");
    if((error = dlerror()) != NULL) {
        fputs(error,stderr);
        exit(1);
    }
    freep(ptr);
    if(print_times == 1) printf("free(%p)\n",ptr);
    print_times = 0;
}

#endif
