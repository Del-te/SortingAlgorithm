let arr = [1, 3, 5, 4, 9, 6];

function quick_sort(arr) {
  // 边界检查
  if (arr.length <= 1) {
    return arr;
  }
  // 选取基准
  let pivotIndex = Math.floor(arr.length / 2);
  let pivot = arr.splice(pivotIndex, 1)[0];
  // 划分子集
  let left = [];
  let right = [];
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] < pivot) {
      left.push(arr[i]);
    }else{
      right.push(arr[i]);
    }
  }
  // 递归进行
  return quick_sort(left).concat([pivot], quick_sort(right));
}

console.log(quick_sort(arr));