let a = [1, 3, 5, 4, 2, 6];

function bublesort() {
  let len = a.length;
  for(let i = 0; i < len; i++) {
    for (let j = 0; j < len - 1 - i; j++) {
      if (a[j] > a[j+1]) {
        let t = a[j+1];
        a[j+1] = a[j];
        a[j] = t;
      }

    }
  }
  return a;
}
console.log(bublesort(a));