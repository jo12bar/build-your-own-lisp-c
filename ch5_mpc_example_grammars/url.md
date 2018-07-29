# URL

## Textual description
Defines web URLs, such as `http://www.buildyourownlisp.com`,
`https://example.com/foo.html?bar=baz`, `http://192.0.0.1:3000/`, etc.

A `<protocol>` is one of `http` or `https`.

A `<ip_v4_address>` is:
- Three digits
- Followed by a `.`
- Followed by a digit
- Followed by a `.`
- Followed by a digit
- Followed by a `.`
- Followed by one or two digits.

A `<dns_address>` is:
- An optional amount of subdomains, which are:
  - A string of lowercase letters
  - Followed by a `.`
- Followed by a domain, which is a string of lowercase letters
- Followed by a `.`
- Followed by a TLD (Top Level Domain), which is one of `com`, `ca`, `org`,
  `gov`, `net`, or `io` only (for now&mdash;this is just a simple definition!).

A `<port>` is:
- A `:`
- Followed by at least one numerical digit.

A `<host>` is:
- Either a `<ip_v4_address>` or a `<dns_address>`
- Optionally followed by a `<port>`

A `<file_extension` is:
- A `.`
- Followed by a string (the extension)

A `<path>` is:
- A string , followed optionally by either:
  - A single `<file_extension>`
  - A `/`
  - Or:
    - A `/`
	- Followed by a `<path>`

A `<param>` is:
- A string (the key)
- Followed by a `=`
- Optionally followed by a string (the value)
- Optionally follwed by `&` and another `<param>`

A `<url>` is:
- A `<protocol>`
- Followed by `://`
- Followed by a `<host>`
- Optionally followed by:
  - A `/`
  - Optionally followed by `<path>`
  - Optionally followed by:
    - A `?`
	- Followed by a `<param>`

## `mpc` description

```
protocol       : "http" | "https" ;

ip_v4_address  : /[0-9]{3}/ '.' /[0-9]/ '.' /[0-9]/ '.' /[0-9]{1,2}/ ;
dns_address    : (/[a-z]+/ '.')* /[a-z]+/ '.' ("com" | "ca" | "org" | "gov" | "net" | "io") ;
port           : ':' /[0-9]+/ ;
host           : (<ip_v4_address> | <dns_address>) <port>* ;

file_extension : '.' /\s+/ ;
path           : /\s+/ (<file_extension> | '/' | ('/' <path>)*)* ;

param_key      : /\s+/ ;
param_value    : /\s+/ ;
param          : <param_key> '=' <param_value>* ('&' <param>)* ;

url            : <protocol> "://" <host> '/'* <path>* ('?' <param>)* ;
```
