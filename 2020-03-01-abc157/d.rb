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

  def root(a)
    return a if @data[a] < 0
    @data[a] = root(@data[a])
  end

  def size(a)
    return -@data[root(a)]
  end
end

n, m, k = gets.chomp.split.map(&:to_i)

uf = UnionFind.new(n)

friend = Array.new(n, 0)
block = Array.new(n) { Array.new }

m.times do
  a, b = gets.chomp.split.map(&:to_i)
  a -= 1
  b -= 1
  friend[a] += 1
  friend[b] += 1
  uf.union_set(a, b)
end

k.times do
  a, b = gets.chomp.split.map(&:to_i)
  a -= 1
  b -= 1
  block[a].push(b)
  block[b].push(a)
end

n.times do |i|
  res = uf.size(i) - 1 - friend[i]
  block[i].each do |k|
    res -= 1 if uf.find_set(i, k)
  end
  print ' ' if i != 0
  print res
end
puts ''
