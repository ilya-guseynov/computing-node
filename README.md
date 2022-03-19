# Computing Node

Package for improving perfomance of computing tasks in Node.js

## Building

### Install node.js

```shell
$ curl -fsSL https://deb.nodesource.com/setup_17.x | sudo -E bash -
$ sudo apt-get install -y nodejs
```

### Install node.js (EXTRA)

Install n package to work with node and npm versions.

```shell
$ sudo npm i -g n
```

Install latest node version.

```shell
$ sudo n latest
```

### Install packages for native addons

```shell
$ sudo apt-get install gcc g++ make
```

```shell
$ npm install
$ npm run configure
$ npm run build
```

## Test

```shell
$ npm test
```