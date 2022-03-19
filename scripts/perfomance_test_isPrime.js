const { performance } = require('node:perf_hooks')
const { isPrime } = require('../index.js')

const pureIsPrime = n => {
  if (n < 2) {
    return false
  }

  if (n === 2) {
    return true
  }

  if (n % 2 === 0) {
    return false
  }

  for (let i = 3; (i*i)<=n; i+=2) {
    if (n % i === 0) {
      return false
    }
  }

  return true
}

const main = () => {
  for (let number = 1; number < 100_000_000_000_000; number += 1) {
    const jsStart = performance.now()
    const jsResult = pureIsPrime(number)
    const jsEnd = performance.now()

    const jsTime = jsEnd - jsStart

    const cppStart = performance.now()
    const cppResult = isPrime(number)
    const cppEnd = performance.now()

    const cppTime = cppEnd - cppStart

    if (jsTime > cppTime && cppResult === true) {
      const diff = jsTime - cppTime

      if (diff > 0.01) {
        console.log(`isPrime(${number}) = ${cppResult}. C++ is faster for ${diff}ms`)
      }
    }

    if (jsResult !== cppResult) {
      console.log(`On number ${number} results are not the same.`)
      return
    }
  }
}

main()
