const { performance } = require('node:perf_hooks')
const { createMatrix } = require('./_helpers.js')
const { matrixSum } = require('../index.js')

const pureMatrixSum = (someMatrixA, someMatrixB) => {
  let result = []

  for (let i = 0; i < someMatrixA.length; i++) {
    result.push([])

    for (let j = 0; j < someMatrixA[i].length; j++) {
      result[i][j] = someMatrixA[i][j] + someMatrixB[i][j]
    }
  }

  return result
}

const main = () => {
  for (let number = 1; number < 100_000_000; number += 100) {
    const someMatrix = createMatrix(number)

    const jsStart = performance.now()
    const jsResult = pureMatrixSum(someMatrix, someMatrix)
    const jsEnd = performance.now()

    const jsTime = jsEnd - jsStart

    const cppStart = performance.now()
    const cppResult = matrixSum(someMatrix, someMatrix)
    const cppEnd = performance.now()

    const cppTime = cppEnd - cppStart

    if (jsTime > cppTime) {
      const diff = jsTime - cppTime
      console.log(`matrixSum(${number}). C++ is faster by ${diff}ms`)
    } else {
      const diff = cppTime - jsTime
      console.log(`matrixSum(${number}). Node.js is faster by ${diff}ms`)
    }

    if (jsResult.length !== cppResult.length) {
      console.log(`On matrix size ${ number } results are not the same.`)
      return
    }
  }
}

main()
