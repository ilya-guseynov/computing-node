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
})
