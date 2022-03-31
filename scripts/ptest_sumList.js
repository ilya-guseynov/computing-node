const { performance } = require('node:perf_hooks')
const { createVector } = require('./_helpers.js')
const { sumList } = require('../index.js')

const pureSumList = someList => {
  let result = 0

  someList.forEach(num => {
    result += num
  })

  return result
}

const main = () => {
  const CPP_LABEL = 'Calculate via C++'
  const JS_LABEL = 'Calculate via JS '

  for (let number = 1; number < 100_000_000; number += 100) {
    const someList = createVector(number)

    const jsStart = performance.now()
    const jsResult = pureSumList(someList)
    const jsEnd = performance.now()

    const jsTime = jsEnd - jsStart

    const cppStart = performance.now()
    const cppResult = sumList(someList)
    const cppEnd = performance.now()

    const cppTime = cppEnd - cppStart

    if (jsTime > cppTime) {
      const diff = jsTime - cppTime
      console.log(`sumList(${number}). C++ is faster by ${diff}ms`)
    } else {
      const diff = cppTime - jsTime
      console.log(`sumList(${number}). Node.js is faster by ${diff}ms`)
    }

    if (jsResult.length !== cppResult.length) {
      console.log(`On list size ${ number } results are not the same.`)
      return
    }
  }
}

main()
