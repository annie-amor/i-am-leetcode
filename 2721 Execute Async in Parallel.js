/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = async function(functions) {
    return new Promise((resolve, reject) => {
        const values = [];
        let count = 0;
        let rejected = false;

        for(const i in functions){
            functions[i]()
            .then(res => {
                if(!rejected){
                    count++;
                    values[i] = res;

                    if(count === functions.length)
                        resolve(values)
                }
            })

            .catch(err =>{
                if(!rejected){
                    rejected = true;
                    reject(err);
                }
            });
        }
        
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */