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
      
      if(rotate_board[row].length === 0) continue;
      
      if(stack.length === 0) {
          stack.push(rotate_board[row].pop());
      }
      else {
          let last_idx = rotate_board[row].length-1;
          if(stack[stack.length-1] === rotate_board[row][last_idx]) {
              rotate_board[row].pop();
              stack.pop(); 
              answer += 2;
          }
          else {
              stack.push(rotate_board[row].pop());
          }
      }
  }
  
  return answer;
}