const { performance } = require('node:perf_hooks')
const { eulerTotient } = require('../index.js')


function gcd(a, b) {
  if (a === 0) {
    return b
  }

  return gcd(b % a, a)
}

function pureEulerTotient(n) {
  let result = 1

  for (let i = 2; i < n; i++) {
    if (gcd(i, n) === 1) {
      result++
    }
  }

  return result
}

const main = () => {
  for (let number = 1; number < 1_000_000_000; number += 100) {
    const jsStart = performance.now()
    const jsResult = pureEulerTotient(number)
    const jsEnd = performance.now()

    const jsTime = jsEnd - jsStart

    const cppStart = performance.now()
    const cppResult = eulerTotient(number)
    const cppEnd = performance.now()

    const cppTime = cppEnd - cppStart

    if (jsTime > cppTime) {
      const diff = jsTime - cppTime
      console.log(`eulerTotient(${number}). C++ is faster by ${diff}ms`)
    } else {
      const diff = cppTime - jsTime
      console.log(`eulerTotient(${number}). Node.js is faster by ${diff}ms`)
    }

    if (jsResult !== cppResult) {
      console.log(`On number ${number} results are not the same.`)
      return
    }
  }
}

main()
