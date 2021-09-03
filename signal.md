# 信号相关

- SA_RESTART
    - 系统中断，要从[慢系统调用(slow system call)](http://blog.csdn.net/benkaoya/article/details/17262053)说起。慢系统调用就是会阻塞的函数调用，一般是IO调用或有锁的函数。如read,sem_timedwait，这些函数可以会阻塞当前进程一段时间，所以"慢"。在阻塞的这段时间里，进程可能会收到内核的一些信号，这些信号优先级高，需要优先处理的，不能等这些调用完成后才处理信号。于是系统先去处理信号，然后强制这些函数以出错的形式返回，其错误码(errno)就是EINTR。这整个过程就是系统中断。  
    - 在新的信号处理函数sigaction中可以指定收到某个信号时是否可以自动恢复函数执行(即在处理完消息后，继续执行原来中断的函数，像什么也没发生一样)[link](http://www.gnu.org/software/libc/manual/html_node/Flags-for-Sigaction.html)

- sigfillset

    ```
    int sigfillset(sigset_t *set);
    ```
  - sigfillset()用来将参数set信号集初始化，然后把所有的信号加入到此信号集里即将所有的信号标志位置为1，屏蔽所有的信号
