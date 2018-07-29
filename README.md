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

## Language Spec

Currently just an implementation of
[polish notation](http://en.wikipedia.org/wiki/Polish_notation), but this
should make it trivial to implement the rest of Lispy as all Lisps use
polish-notation-like grammar.

A *program* is an *operator* followed by one or more *expressions*, where an
*expression* is either a *number*, or, in parentheses, an *operator* followed by
one or more *expressions*.

More formally:

| Symbol         | Definition                                                                              |
|----------------|-----------------------------------------------------------------------------------------|
| `<program>`    | The start of input, an `<operator>`, one or more `<expression>`s, and the end of input. |
| `<expression>` | Either a `<number>` or a `(`, an `<operator>`, one or more `<expression>`s, and a `)`.  |
| `<operator>`   | `+`, `-`, `*`, or `/`.                                                                  |
| `<number>`     | An optional `-`, and one or more characters between 0 and 9 (inclusive).                |
