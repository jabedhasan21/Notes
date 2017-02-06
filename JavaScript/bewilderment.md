+
```
var x = 0;
function f() {
  var x = m = y = 10; // x is declared locally. y is not!
  // what happend if we do this
  //var  m = y = 10;
}
f();
console.log(x, y);
console.log(m, y);
var w = e , e = 'A';
console.log(w + e); // undefinedA
```
