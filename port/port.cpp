extern "C"
{
    // The interface __stack_chk_fail() shall abort the function that called it with a message 
    // that a stack overflow has been detected. 
    // The program that called the function shall then exit.
    void __stack_chk_fail(void)
    {
    }

}