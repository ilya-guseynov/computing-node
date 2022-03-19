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

    console.time(JS_LABEL)
    const jsResult = pureSumList(someList)
    console.timeEnd(JS_LABEL)

    console.time(CPP_LABEL)
    const cppResult = sumList(someList)
    console.timeEnd(CPP_LABEL)

    if (jsResult !== cppResult) {
      console.log(`On vector size ${ number } results are not the same.`)
      return
    }
  }
}

main()
