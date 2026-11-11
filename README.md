# finit

Historically first real system init[^1][^2] for Utopia.

[^1]: Previously, random programs that were not written with the intention of running as system inits (like [JUAMP](https://github.com/gorciu-official/JUAMP), [nsh](https://github.com/na-razie-bez-nicku/nsh/tree/main) or [bash](https://www.gnu.org/software/bash/)), were running as PID 1 through the Linux compatibility layer.
[^2]: Technically, the fsstrap-bundled PID 1 was first, but this is the exact init, except now maintained out of fsstrap's source tree.
