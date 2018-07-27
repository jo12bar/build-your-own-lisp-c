# Build Your Own Lisp in C (my implementation)

My implementation of a Lisp as described in [this book](http://www.buildyourownlisp.com/chapter2_installation).
The `master` branch should always work, be deployable, even if it isn't
actually working as a "programming language". All in-development work should be
done on their own respective branches, be merged in via a pull request, and
promptly removed. I know that I'm the only one working on this, so it's not
really necessary, but I'm treating it as an exercise in programming
cleanliness. I might add things, remove things... Let's see what I can do :grin:

## Building

### Requirements
- GNU `make`, `gcc` (or just `cc`&mdash;basically the same thing), etc... If
  you're using Debian or Ubuntu or similar you can just
  `sudo apt install build-essential` to get all of these tools.
- The `editline` development library
  - __*Mac*__: Should be installed with the *Command Line Tools*.
  - __*Debian, Ubuntu, etc*__: `sudo apt install libedit-dev`
  - __*Fedora, etc*__: `su -c "yum install libedit-dev*"`
