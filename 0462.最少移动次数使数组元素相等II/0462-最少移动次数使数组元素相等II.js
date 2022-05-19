/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves2 = function(nums) {
    let moves = 0;
    //https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/sort
    nums.sort((a, b) => a - b);
    let mid = nums[Math.floor(nums.length/2)];
    for(let i=0; i<nums.length; i++) {
        moves += Math.abs(nums[i] - mid);
    }
    return moves;
};