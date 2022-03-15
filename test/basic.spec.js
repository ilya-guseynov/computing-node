const ComputingNode = require('../index.js')

describe('ComputingNode / basic', () => {
  describe('sumList', () => {
    it('must be a function', () => {
      expect(typeof ComputingNode.sumList).toBe('function')
    })

    it('must throw an error if no argument provided', () => {
      expect(() => {
        ComputingNode.sumList()
      }).toThrowError(new Error('Must be provided 1 argument'))
    })

    it('must throw an error if provided two or more arguments', () => {
      expect(() => {
        ComputingNode.sumList([1, 2], 1)
      }).toThrowError(new Error('Must be provided 1 argument'))
    })

    it('must throw an error if provided argument is not an array', () => {
      expect(() => {
        ComputingNode.sumList('some_string')
      }).toThrowError(new Error('Provided argument must be a list'))

      expect(() => {
        ComputingNode.sumList(false)
      }).toThrowError(new Error('Provided argument must be a list'))

      expect(() => {
        ComputingNode.sumList({ foo: 'bar' })
      }).toThrowError(new Error('Provided argument must be a list'))

      expect(() => {
        ComputingNode.sumList(null)
      }).toThrowError(new Error('Provided argument must be a list'))

      expect(() => {
        ComputingNode.sumList(undefined)
      }).toThrowError(new Error('Provided argument must be a list'))

      expect(() => {
        ComputingNode.sumList(() => {})
      }).toThrowError(new Error('Provided argument must be a list'))
    })

    it('must return sum of list of numbers', () => {
      expect(ComputingNode.sumList([1])).toEqual(1)
      expect(ComputingNode.sumList([1, 2])).toEqual(3)
      expect(ComputingNode.sumList([1, 2, 3])).toEqual(6)
      expect(ComputingNode.sumList([1, 2, 3, 4])).toEqual(10)
    })
  })

  describe('isMatrixSquare', () => {
    it('must be a function', () => {
      expect(typeof ComputingNode.isMatrixSquare).toBe('function')
    })

    it('must throw an error if no argument provided', () => {
      expect(() => {
        ComputingNode.isMatrixSquare()
      }).toThrowError(new Error('Must be provided 1 argument'))
    })

    it('must throw an error if provided two or more arguments', () => {
      expect(() => {
        ComputingNode.isMatrixSquare([1, 2], 1)
      }).toThrowError(new Error('Must be provided 1 argument'))
    })

    it('must throw an error if provided argument is not an array', () => {
      expect(() => {
        ComputingNode.isMatrixSquare('some_string')
      }).toThrowError(new Error('Provided argument must be a list'))

      expect(() => {
        ComputingNode.isMatrixSquare(false)
      }).toThrowError(new Error('Provided argument must be a list'))

      expect(() => {
        ComputingNode.isMatrixSquare({ foo: 'bar' })
      }).toThrowError(new Error('Provided argument must be a list'))

      expect(() => {
        ComputingNode.isMatrixSquare(null)
      }).toThrowError(new Error('Provided argument must be a list'))

      expect(() => {
        ComputingNode.isMatrixSquare(undefined)
      }).toThrowError(new Error('Provided argument must be a list'))

      expect(() => {
        ComputingNode.isMatrixSquare(() => {})
      }).toThrowError(new Error('Provided argument must be a list'))
    })

    it('must return true if provided matrix is square', () => {
      expect(ComputingNode.isMatrixSquare([
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
      ])).toBe(true)

      expect(ComputingNode.isMatrixSquare([
        [1, 2],
        [4, 5],
      ])).toBe(true)

      expect(ComputingNode.isMatrixSquare([
        [1],
      ])).toBe(true)

      expect(ComputingNode.isMatrixSquare([
        [1, 2, 3, 0],
        [4, 5, 6, 0],
        [7, 8, 9, 0],
        [7, 8, 9, 0],
      ])).toBe(true)
    })

    it('must return false if provided matrix is not square', () => {
      expect(ComputingNode.isMatrixSquare([
        [1, 2],
        [4, 5, 6],
        [7, 8, 9],
      ])).toBe(false)

      expect(ComputingNode.isMatrixSquare([
        [1],
        [4, 5],
      ])).toBe(false)

      expect(ComputingNode.isMatrixSquare([
        [1, 2],
      ])).toBe(false)

      expect(ComputingNode.isMatrixSquare([
        [1, 2, 3],
        [4, 5, 6, 0],
        [7, 8, 9],
        [7],
      ])).toBe(false)
    })
  })
})
