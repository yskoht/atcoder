
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

n, d, a = gets.chomp.split.map(&:to_i)

ms = []
n.times do
  ms.push gets.chomp.split.map(&:to_i)
end
ms = ms.sort_by { |x| x[0] }
ms.push [1<<60, 0]

dst = {}
n.times do |i|
  x, _ = *ms[i]
  r = x + 2*d
  k = ms.bsearch_index { |m| m[0] > r }
  dst[i] = k
end

bit = BIT.new(n+1)

res = 0
n.times do |i|
  x, h = *ms[i]
  t = bit.sum(i + 1)
  h -= t
  next if h <= 0

  cnt = (h + a - 1) / a
  res += cnt
  damage = cnt * a

  bit.add(i + 1, damage)
  bit.add(dst[i] + 1, -damage)
end

puts res