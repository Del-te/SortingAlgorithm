// <1>.比较相邻的元素。如果第一个比第二个大，就交换它们两个；
// <2>.对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
// <3>.针对所有的元素重复以上的步骤，除了最后一个；
// <4>.重复步骤1~3，直到排序完成。
// 复杂度 O(n2)
let a = [1, 3, 5, 4, 2, 6];

function bublesort() {
  let len = a.length;
  // 一共进行len躺循环
  for(let i = 0; i < len; i++) {
    // 每趟比较len-1-i次
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