const ComputingNode = require('../index.js')

describe('ComputingNode / matrix', () => {
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

    it('must throw an error if provided array is not a correct matrix', () => {
      expect(() => {
        ComputingNode.isMatrixSquare([])
      }).toThrowError(new Error('Provided array is not a correct matrix'))

      expect(() => {
        ComputingNode.isMatrixSquare([[]])
      }).toThrowError(new Error('Provided array is not a correct matrix'))

      expect(() => {
        ComputingNode.isMatrixSquare([
          [],
          [],
        ])
      }).toThrowError(new Error('Provided array is not a correct matrix'))

      expect(() => {
        ComputingNode.isMatrixSquare([1])
      }).toThrowError(new Error('Provided array is not a correct matrix'))

      expect(() => {
        ComputingNode.isMatrixSquare([
          [1, 2, 3],
          [1, 2, 'some_string'],
        ])
      }).toThrowError(new Error('Provided array is not a correct matrix'))

      expect(() => {
        ComputingNode.isMatrixSquare([
          [1, 2, 3],
          [1, 2, false],
        ])
      }).toThrowError(new Error('Provided array is not a correct matrix'))

      expect(() => {
        ComputingNode.isMatrixSquare([
          [1, 2, 3],
          [1, 2, { foo: 'bar' }],
        ])
      }).toThrowError(new Error('Provided array is not a correct matrix'))

      expect(() => {
        ComputingNode.isMatrixSquare([
          [1, 2, 3],
          [1, 2, null],
        ])
      }).toThrowError(new Error('Provided array is not a correct matrix'))

      expect(() => {
        ComputingNode.isMatrixSquare([
          [1, 2, 3],
          [1, 2, undefined],
        ])
      }).toThrowError(new Error('Provided array is not a correct matrix'))

      expect(() => {
        ComputingNode.isMatrixSquare([
          [1, 2, 3],
          [1, 2, () => {}],
        ])
      }).toThrowError(new Error('Provided array is not a correct matrix'))

      expect(() => {
        ComputingNode.isMatrixSquare([
          [1, 2, 3],
          [1, 2, 'some_string'],
        ])
      }).toThrowError(new Error('Provided array is not a correct matrix'))

      expect(() => {
        ComputingNode.isMatrixSquare([
          [1, 2, 3],
          [1, 2]
        ])
      }).toThrowError(new Error('Provided array is not a correct matrix'))
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
        [1, 2, 3],
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
      ])).toBe(false)

      expect(ComputingNode.isMatrixSquare([
        [1, 1],
        [1, 1],
        [4, 5],
      ])).toBe(false)

      expect(ComputingNode.isMatrixSquare([
        [1, 2],
      ])).toBe(false)

      expect(ComputingNode.isMatrixSquare([
        [1, 2, 3, 4],
        [4, 5, 6, 0],
        [7, 8, 9, 5],
        [7, 5, 5, 5],
        [7, 5, 5, 5],
      ])).toBe(false)
    })
  })
})
