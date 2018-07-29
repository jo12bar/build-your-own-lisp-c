# Decimal

## Textual description
This grammar describes decimal numbers, like `0.01` or `52.221`.

A `decimal_number`:
- Has at least one `digit`
- Followed by a `.` (decimal point)
- Followed optionally by an indeterminate number of `digit`s.

A `digit`:
- Is any number from 0 through 9 (a.k.a. something that satisfies the regex
  `/[0-9]/`)

## `mpc` definition

```
digit          : /[0-9]/ ;
decimal_number : <digit>+ '.' <digit>* ;
```
