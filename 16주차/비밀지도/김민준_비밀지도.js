function solution(n, arr1, arr2) {
  let result = [];
  
  for(let i=0; i<n; i++) {
      result.push(arr1[i] | arr2[i]);
  }
  
  result = result.map(item =>
      item.toString(2) // 2진수 문자열로 변환
          .padStart(n, '0') // 길이 n보다 부족한 만큼 앞에 '0'으로 채워줌
          // 0또는 1에 해당하는 것을 숫자로 바꿔준 후, 1이면 '#', 0이면 공백으로 바꿔줌
          .replace(/0|1/g, n => +n ? '#' : ' ') 
  );
  
  return result;
}