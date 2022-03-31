const { performance } = require('node:perf_hooks')
const { createCollatzSequence } = require('../index.js')

function pureCreateCollatzSequence(n) {
  let localN = n
  const seq = [];

  while (localN > 1) {
    seq.push(localN)

    if (localN % 2 === 0) {
      localN = localN / 2;
    } else {
      localN = (3 * localN) + 1;
    }
  }

  return seq
}

const main = () => {
  for (let number = 1; number < 1_000_000_000_0; number += 1) {
    const jsStart = performance.now()
    const jsResult = pureCreateCollatzSequence(number)
    const jsEnd = performance.now()

    const jsTime = jsEnd - jsStart

    const cppStart = performance.now()
    const cppResult = createCollatzSequence(number)
    const cppEnd = performance.now()

    const cppTime = cppEnd - cppStart

    if (jsTime > cppTime) {
      const diff = jsTime - cppTime
      console.log(
        `createCollatzSequence(${number}). C++ is faster by ${diff}ms`
      )
    } else {
      const diff = cppTime - jsTime
      console.log(
        `createCollatzSequence(${number}). Node.js is faster by ${diff}ms`
      )
    }
  }
}

main()
