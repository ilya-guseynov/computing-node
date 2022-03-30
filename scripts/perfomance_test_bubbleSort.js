const { performance } = require('node:perf_hooks')
const { createRandomVector } = require('./_helpers.js')
const { bubbleSort } = require('../index.js')


const pureBubbleSort = providedVector => {
  const vector = [...providedVector]

  for (let i = 0; i < vector.length - 1; i++) {
    let swapped = false

    for (let j = 0; j < vector.length - i - 1; j++) {
      if (vector[j] > vector[j + 1]) {
        swapped = true
        const temp = vector[j + 1]
        vector[j + 1] = vector[j]
        vector[j] = temp
      }
    }

    if (!swapped) {
      break
    }
  }

  return vector
}


const main = () => {
  const CPP_LABEL = 'Calculate via C++'
  const JS_LABEL = 'Calculate via JS '

  for (let number = 10; number < 100_000_000; number += 10) {
    const vector = createRandomVector(number)

    const jsStart = performance.now()
    const jsResult = pureBubbleSort(vector)
    const jsEnd = performance.now()

    const jsTime = jsEnd - jsStart

    const cppStart = performance.now()
    const cppResult = bubbleSort(vector)
    const cppEnd = performance.now()

    const cppTime = cppEnd - cppStart

    if (jsTime > cppTime) {
      const diff = jsTime - cppTime
      console.log(`bubbleSort(${number}). C++ is faster by ${diff}ms`)
    } else {
      const diff = cppTime - jsTime
      console.log(`bubbleSort(${number}). Node.js is faster by ${diff}ms`)
    }

    if (JSON.stringify(jsResult) !== JSON.stringify(cppResult)) {
      console.log(`On list size ${ number } results are not the same.`)
      return
    }
  }
}

main()
