//index.js
const winfo = require('./build/Release/winfo.node');
let test = true;
if (test) {
    console.log('Object:', winfo);
    console.log('Title:', winfo.title());
    console.log('id:' + winfo.id()); // note yet implemented
    console.log('x:' + winfo.x());
    console.log('y:' + winfo.y());
    console.log('width:' + winfo.width());
    console.log('height' + winfo.height());
}

module.exports = winfo;