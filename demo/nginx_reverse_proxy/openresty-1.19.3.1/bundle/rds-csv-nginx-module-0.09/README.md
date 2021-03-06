Name
====

ngx_rds_csv - Nginx output filter module to convert Resty-DBD-Streams
(RDS) to Comma-Separated Values (CSV)

Table of Contents
=================

* [Name](#name)
* [Status](#status)
* [Synopsis](#synopsis)
* [Description](#description)
* [Directives](#directives)
    * [rds_csv](#rds_csv)
    * [rds_csv_row_terminator](#rds_csv_row_terminator)
    * [rds_csv_field_separator](#rds_csv_field_separator)
    * [rds_csv_field_name_header](#rds_csv_field_name_header)
    * [rds_csv_content_type](#rds_csv_content_type)
    * [rds_csv_buffer_size](#rds_csv_buffer_size)
* [Installation](#installation)
* [Compatibility](#compatibility)
* [Author](#author)
* [Copyright & License](#copyright--license)
* [See Also](#see-also)

Status
======

This module is considered production ready.

Synopsis
========

```nginx
location /foo {
    # drizzle_pass/postgres_pass/...

    rds_csv on;
    rds_csv_row_terminator "\n"; # default to "\r\n"
}
```

Description
===========

This module implements an efficient output filter that converts
Resty-DBD-Streams (RDS) generated by [ngx_drizzle](https://github.com/openresty/drizzle-nginx-module)
and [ngx_postgres](https://github.com/FRiCKLE/ngx_postgres/)
to Comma-Separated Values (CSV) format in a streaming fashion.
By default, the CSV format is in compliance with [RFC 4180](http://tools.ietf.org/html/rfc4180):

http://tools.ietf.org/html/rfc4180

SQL NULL values will be converted to empty field value, just like
empty string values.

[Back to TOC](#table-of-contents)

Directives
==========

[Back to TOC](#table-of-contents)

rds_csv
-------
**syntax:** *rds_csv on|off*

**default:** *rds_csv off*

**context:** *http, server, location, location if*

Enables this output filter when on and disables otherwise.

[Back to TOC](#table-of-contents)

rds_csv_row_terminator
----------------------

**syntax:** *rds_csv_row_terminator &lt;str&gt;*

**default:** *rds_csv_row_terminator "\r\n"*

**context:** *http, server, location, location if*

Specifies the row terminator used by the CSV format.
Only `"\r\n"` and `"\n"` are allowed.

Defaults to `"\r\n"`, i.e., CR LF, according to [RFC 4180](http://tools.ietf.org/html/rfc4180).

[Back to TOC](#table-of-contents)

rds_csv_field_separator
-----------------------

**syntax:** *rds_csv_field_separator &lt;char&gt;*

**default:** *rds_csv_field_separator ","*

**context:** *http, server, location, location if*

Specifies the field seperator used by the CSV format.
Only `","`, `";"`, and `"\t"` are allowed.

Defaults to `","` according to [RFC 4180](http://tools.ietf.org/html/rfc4180).

[Back to TOC](#table-of-contents)

rds_csv_field_name_header
-------------------------

**syntax:** *rds_csv_field_name_header on|off*

**default:** *rds_csv_field_name_header off*

**context:** *http, server, location, location if*

Emits the first line of field names when this directive is set on,
and none otherwise.

[Back to TOC](#table-of-contents)

rds_csv_content_type
--------------------
**syntax:** *rds_csv_content_type &lt;str&gt;*

**default:** *rds_csv_content_type "text/csv; header=&lt;present|absence&gt;"*

**context:** *http, server, location, location if*

Specifies the `Content-Type` response header generated by this module.

Defaults to `"text/csv; header=present"` or `"text/csv; header=absence"`,
depending on whether [rds_csv_field_name_header](#rds_csv_field_name_header) is on or off.

[Back to TOC](#table-of-contents)

rds_csv_buffer_size
-------------------
**syntax:** *rds_csv_buffer_size &lt;size&gt;*

**default:** *rds_csv_buffer_size 4k/8k*

**context:** *http, server, location, location if*

The lager this buffer size setting, the less streammy the output
will be.

[Back to TOC](#table-of-contents)

Installation
============

You're recommended to install this module (as well as the Nginx core and many other goodies) via the [ngx_openresty bundle](http://openresty.org). See [the detailed instructions](http://openresty.org/#Installation) for downloading and installing ngx_openresty into your system. This is the easiest and most safe way to set things up.

Alternatively, you can install this module manually with the Nginx source:

Grab the nginx source code from [nginx.org](http://nginx.org/), for example,
the version 1.13.6 (see [nginx compatibility](#compatibility)), and then build the source with this module:

```bash

 $ wget 'http://nginx.org/download/nginx-1.13.6.tar.gz'
 $ tar -xzvf nginx-1.13.6.tar.gz
 $ cd nginx-1.13.6/

 # Here we assume you would install you nginx under /opt/nginx/.
 $ ./configure --prefix=/opt/nginx \
     --add-module=/path/to/rds-csv-nginx-module

 $ make -j2
 $ make install
```

Download the latest version of the release tarball of this module from [rds-csv-nginx-module file list](https://github.com/openresty/rds-csv-nginx-module/tags).

Also, this module is included and enabled by default in the [ngx_openresty bundle](http://openresty.org).

[Back to TOC](#table-of-contents)

Compatibility
=============

This module is compatible with the following versions of Nginx:

* **1.13.x** (last tested: 1.13.6)
* **1.12.x**
* **1.11.x** (last tested: 1.11.2)
* **1.10.x**
* **1.9.x** (last tested: 1.9.7)
* **1.8.x**
* **1.7.x** (last tested: 1.7.10)
* **1.6.x**
* **1.5.x**
* **1.4.x** (last tested: 1.4.3)
* **1.2.x** (last tested: 1.2.9)
* **1.1.x** (last tested: 1.1.5)
* **1.0.x** (last tested: 1.0.8)

[Back to TOC](#table-of-contents)

Author
======
Yichun "agentzh" Zhang &lt;agentzh@gmail.com&gt;, OpenResty Inc.

[Back to TOC](#table-of-contents)

Copyright & License
===================
This module is licenced under the BSD license.

Copyright (C) 2011-2018, Yichun "agentzh" Zhang (?????????) &lt;agentzh@gmail.com&gt;, OpenResty Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

* Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

[Back to TOC](#table-of-contents)

See Also
========

* [ngx_drizzle](https://github.com/openresty/drizzle-nginx-module)
* [ngx_postgres](https://github.com/FRiCKLE/ngx_postgres/)
* [ngx_rds_json](https://github.com/openresty/rds-json-nginx-module)

[Back to TOC](#table-of-contents)

