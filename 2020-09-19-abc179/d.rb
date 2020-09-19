# Binary Indexed Tree
# https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees
# http://hos.ac/slides/20140319_bit.pdf
class BIT
  def initialize(n)
    @tree = Array.new(n + 1, 0)
  end

  def add(i, diff)
    while i < @tree.size
      @tree[i] += diff
      i += (i & -i)
    end
  end

  def sum(i)
    t = 0
    while i > 0 do
      t += @tree[i]
      i -= (i & -i)
    end
    return t
  end
end

n, k = gets.chomp.split.map(&:to_i)

bit = BIT.new(n)
bit.add(1, 1)

rng = []
k.times do
  l, r = gets.chomp.split.map(&:to_i)
  rng.push([l, r])
end

2.upto(n) do |i|
  t = 0

  rng.each do |a, b|
    aa = i - a
    bb = i - b - 1

    aa = 0 if aa < 0
    bb = 0 if bb < 0

    t += bit.sum(aa) - bit.sum(bb)
  end

  bit.add(i, t % 998244353)
end

puts bit.sum(n) - bit.sum(n-1)
