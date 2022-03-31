const { performance } = require('node:perf_hooks')
const { binomialCoeff } = require('../index.js')

function pureBinomailCoeff(n, k) {
  if (k > n) {
    return 0
  }

  if (k === 0 || k === n) {
    return 1
  }

  return pureBinomailCoeff(n - 1, k - 1) + pureBinomailCoeff(n - 1, k)
}

const main = () => {
  const LIMIT = 1_000
  const STEP = 1

  for (let k = 1; k < LIMIT; k += STEP) {
    for (let n = k; n < LIMIT; n += STEP) {
      const jsStart = performance.now()
      const jsResult = pureBinomailCoeff(n, k)
      const jsEnd = performance.now()

      const cppStart = performance.now()
      const cppResult = binomialCoeff(n, k)
      const cppEnd = performance.now()

      const jsTime = jsEnd - jsStart
      const cppTime = cppEnd - cppStart

      if (cppResult === 0 && jsResult === 0) {
        continue
      }

      if (jsTime > cppTime) {
        const diff = jsTime - cppTime
        console.log(`binomialCoeff(${n}, ${k}) = ${cppResult}. C++ is faster by ${diff}ms`)
      } else {
        const diff = cppTime - jsTime
        console.log(`binomialCoeff(${n}, ${k}) = ${jsResult}. Node.js is faster by ${diff}ms`)
      }

      if (jsResult !== cppResult) {
        console.log(`On n = ${n} k = ${k} results are not the same.`)
        return
      }
    }

  }
}

main()
