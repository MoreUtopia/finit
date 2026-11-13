# finit

Historically first real system init for the [Utopia](https://github.com/gorciu-official/Utopia/) kernel that emerged from [fsstrap](https://github.com/MoreUtopia/fsstrap). Its job is to launch another init executable using the Linux syscall ABI, which exposes more functionality to the running programs.

Uses the [ulibc](https://github.com/MoreUtopia/ulibc) C standard library.
