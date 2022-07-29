// 게임 화면을 오른쪽 90도 rotate
function rotate(board){
  let result = [];
  let len = board.length;
  
  for(let i=0; i<len; i++) {
      let tmp = [];
      for(let j=0; j<len; j++) {
          tmp.push(board[j][i]);
      }
      tmp = tmp.reverse().filter(item => item !== 0);
      result.push(tmp);
  }
  
  return result;
}

function solution(board, moves) {
  let answer = 0;
  let rotate_board = [];
  let stack = [];
  
  rotate_board = rotate(board);
  console.log(rotate_board);
  
  for(let i=0; i<moves.length; i++) {
      let row = moves[i] - 1;
      
      // 뽑을 것이 없다면,
      if(rotate_board[row].length === 0) continue;
      
      // 스택이 비어있다면 뽑은 것 그냥 push
      if(stack.length === 0) {
          stack.push(rotate_board[row].pop());
      }
      // 스택이 비어있지 않다면,
      else {
          let last_idx = rotate_board[row].length-1;
          // 스택의 맨위와 뽑은것이 같다면,
          if(stack[stack.length-1] === rotate_board[row][last_idx]) {
              // 굳이 push할 필요없이 pop해서 스택의 맨위와 뽑은것 없애버린후,
              // answer에 2를 더해줌
              rotate_board[row].pop();
              stack.pop(); 
              answer += 2;
          }
          // 스택의 맨위와 뽑은것이 같지 않다면, push
          else {
              stack.push(rotate_board[row].pop());
          }
      }
  }
  
  return answer;
}