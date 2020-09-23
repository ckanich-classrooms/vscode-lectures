# lecture 7

## how do we make new processes?

demo spawn

demo fork

## how do we do basic profiling?

demo test spawn and test fork at different malloc sizes

## how do we see what's going on under the covers?

strace spawn, strace fork - they're both just using `clone` to do their job.

clone is the swiss army knife of creating new processes. It gives you options for 