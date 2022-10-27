/* 보석 상자 */
const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : '../input.txt';
// const filePath = process.platform === 'linux' ? '/dev/stdin' : 'BOJ/input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const [N, M] = input.shift().split(' ').map(Number);
const colorList = input.map(Number);

function solution(N, M, colorList) {
  let min = 0;
  let max = Math.max(...colorList);

  let mid = 0;
  while (min <= max) {
    mid = Math.floor((min + max) / 2);

    let studentNum = 0;
    colorList.map((color) => {
      studentNum += Math.ceil(color / mid);
    });

    if (studentNum <= N) max = mid - 1;
    else if (studentNum > N) min = mid + 1;
  }

  const RESULT = min;
  console.log(RESULT);
}

solution(N, M, colorList);
