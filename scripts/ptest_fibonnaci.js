const { performance } = require('node:perf_hooks')
const { fibonacci } = require('../index.js')

const pureFibonnaci = n => {
  if (n < 1) {
    return 1
  }

  return pureFibonnaci(n - 1) + pureFibonnaci(n - 2)
}

const main = () => {
  for (let number = 1; number < 1000; number += 1) {
    const jsStart = performance.now()
    const jsResult = pureFibonnaci(number)
    const jsEnd = performance.now()

    const jsTime = jsEnd - jsStart

    const cppStart = performance.now()
    const cppResult = fibonacci(number)
    const cppEnd = performance.now()

    const cppTime = cppEnd - cppStart

    if (jsTime > cppTime) {
      const diff = jsTime - cppTime

      if (diff > 0.01) {
        console.log(`fibonacci(${number}) = ${cppResult}. C++ is faster by ${diff}ms`)
      }
    }

    if (jsResult !== cppResult) {
      console.log(`On number ${number} results are not the same.`)
      return
    }
  }
}

main()
