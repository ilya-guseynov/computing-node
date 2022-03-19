const { fibonacci } = require('../index.js')

const pureFibonnaci = n => {
  if (n < 1) {
    return 1
  }

  return pureFibonnaci(n - 1) + pureFibonnaci(n - 2)
}

const main = () => {
  const CPP_LABEL = 'Calculate via C++'
  const JS_LABEL = 'Calculate via JS '

  for (let number = 1; number < 100; number += 1) {

    console.time(JS_LABEL)
    const jsResult = pureFibonnaci(number)
    console.timeEnd(JS_LABEL)

    console.time(CPP_LABEL)
    const cppResult = fibonacci(number)
    console.timeEnd(CPP_LABEL)

    if (jsResult !== cppResult) {
      console.log(`On vector size ${ number } results are not the same.`)
      return
    }
  }
}

main()
