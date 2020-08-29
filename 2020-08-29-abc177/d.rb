# Union Find
# http://www.prefield.com/algorithm/container/union_find.html
class UnionFind
  def initialize(n)
    @data = Array.new(n, -1)
  end

  def union_set(a, b)
    a = root(a)
    b = root(b)
    if a != b
      a, b = b, a if @data[b] < @data[a]
      @data[a] += @data[b]
      @data[b] = a
    end
    return a != b
  end

  def find_set(a, b)
    root(a) == root(b)
  end

  def size(a)
    return -@data[root(a)]
  end

  def root(a)
    return a if @data[a] < 0
    @data[a] = root(@data[a])
  end
end

n, m = gets.chomp.split.map(&:to_i)

uf = UnionFind.new(n)
m.times do
  a, b = gets.chomp.split.map(&:to_i)
  a -= 1
  b -= 1

  uf.union_set(a, b)
end

res = 0
n.times do |i|
  res = [res, uf.size(i)].max
end

puts res
