/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const newArr = [];

    for(const i in arr){
        newArr.push(fn((arr[i]), Number(i)))
    }

    return newArr;
};