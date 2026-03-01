// VARIABLE LENGTH ARRAY (VLA)

// A VLA lets you declare an array whose size is known only at runtime.
// It compiles and may even run fine for small values of n.

// Problems:
//    1. The memory still comes from the STACK, which is very limited
//       (~1-8 MB). A large n silently overflows the stack -> undefined behavior.
//    2. There is NO way to check whether the allocation succeeded.
//    3. VLAs were made optional in C11 and are banned in many codebases
//       (e.g. the Linux kernel). Do not rely on them.


int main(void){
    int n;
    n = 5;
    char ar[n]; // VLA: size decided at runtime, but still on the stack
    return(0);
}
