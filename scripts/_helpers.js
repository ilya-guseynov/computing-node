const createVector = size => {
  const result = []

  for (let i = 0; i < size; i++) {
    result.push(i + 1)
  }

  return result
}

module.exports = {
  createVector,
}
