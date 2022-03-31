const { performance } = require('node:perf_hooks')
const { estimatePiNumber } = require('../index.js')

function pureEstimatePiNumber(points) {
  let i = points
  let inside = 0

  while (i-- > 0) {
    let x = Math.random()
    let y = Math.random()

    if ((x * x) + (y * y) <= 1) {
      inside++
    }
  }

  return (inside / points) * 4
}

const main = () => {
  for (let number = 1; number < 1_000_000_000_0; number += 1_000_000) {
    const jsStart = performance.now()
    const jsResult = pureEstimatePiNumber(number)
    const jsEnd = performance.now()

    const jsTime = jsEnd - jsStart

    const cppStart = performance.now()
    const cppResult = estimatePiNumber(number)
    const cppEnd = performance.now()

    const cppTime = cppEnd - cppStart

    if (jsTime > cppTime) {
      const diff = jsTime - cppTime
      console.log(
        `estimatePiNumber(${number}) = ${cppResult}. C++ is faster by ${diff}ms`
      )
    } else {
      const diff = cppTime - jsTime
      console.log(
        `estimatePiNumber(${number}) = ${cppResult}. Node.js is faster by ${diff}ms`
      )
    }
  }
}

main()
