# Winfo
A small library that retrieve information about the active window (windows only)

# Installation
```bash
$ npm install winfo
```

# Usage
```es6
const winfo = require('winfo');

console.log(winfo.title());   // Title
console.log(winfo.id());      // PID (note yet implemented)
console.log(winfo.x());       // Position X
console.log(winfo.y());       // Position Y
console.log(winfo.width());   // Window width
console.log(winfo.height());  // Window heigth
```
# License
MIT
