const { performance } = require('node:perf_hooks')
const { newmanConway } = require('../index.js')

const pureNewmanConway = n => {
  if (n == 1 || n == 2) {
    return 1
  }

  return pureNewmanConway(pureNewmanConway(n - 1))
    + pureNewmanConway(n - pureNewmanConway(n - 1))
}

const main = () => {
  for (let number = 1; number < 1_000_000; number += 1) {
    const jsStart = performance.now()
    const jsResult = pureNewmanConway(number)
    const jsEnd = performance.now()

    const cppStart = performance.now()
    const cppResult = newmanConway(number)
    const cppEnd = performance.now()

    const jsTime = jsEnd - jsStart
    const cppTime = cppEnd - cppStart

    if (jsTime > cppTime) {
      const diff = jsTime - cppTime
      console.log(`newmanConway(${number}) = ${cppResult}. C++ is faster by ${diff}ms`)
    } else {
      const diff = cppTime - jsTime
      console.log(`newmanConway(${number}) = ${cppResult}. Node.js is faster by ${diff}ms`)
    }

    if (jsResult !== cppResult) {
      console.log(`On number ${number} results are not the same.`)
      return
    }
  }
}

main()
