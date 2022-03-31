const { performance } = require('node:perf_hooks')
const { catalan } = require('../index.js')

function pureCatalan(n) {
  if (n <= 1) {
    return 1
  }

  let res = 0

  for (let i = 0; i < n; i++) {
    res += pureCatalan(i) * pureCatalan(n - i - 1);
  }

  return res;
}

const main = () => {
  for (let number = 1; number < 1000; number += 1) {
    const jsStart = performance.now()
    const jsResult = pureCatalan(number)
    const jsEnd = performance.now()

    const jsTime = jsEnd - jsStart

    const cppStart = performance.now()
    const cppResult = catalan(number)
    const cppEnd = performance.now()

    const cppTime = cppEnd - cppStart

    if (jsTime > cppTime) {
      const diff = jsTime - cppTime
      console.log(`catalan(${number}) = ${cppResult}. C++ is faster by ${diff}ms`)
    }

    if (jsResult !== cppResult) {
      console.log(`On number ${number} results are not the same.`)
      return
    }
  }
}

main()
