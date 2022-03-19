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
  const CPP_LABEL = 'Calculate via C++'
  const JS_LABEL = 'Calculate via JS '

  for (let number = 10; number < 100_000_000; number += 100) {
    const someMatrix = createMatrix(number)

    console.time(JS_LABEL)
    const jsResult = pureMatrixSum(someMatrix, someMatrix)
    console.timeEnd(JS_LABEL)

    console.time(CPP_LABEL)
    const cppResult = matrixSum(someMatrix, someMatrix)
    console.timeEnd(CPP_LABEL)

    if (jsResult.length !== cppResult.length) {
      console.log(`On vector size ${ number } results are not the same.`)
      return
    }
  }
}

main()
