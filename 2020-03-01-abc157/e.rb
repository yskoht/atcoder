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


n = gets.to_i
bits = Hash.new
('a'..'z').each do |c|
  bits[c] = BIT.new(n)
end

s = gets.chomp
n.times do |i|
  bits[s[i]].add(i + 1, 1)
end

q = gets.to_i
q.times do
  t, a, b = gets.chomp.split
  t = t.to_i
  if t == 1
    i = a.to_i - 1
    c = b
    if s[i] != c
      bits[s[i]].add(i + 1, -1)
      s[i] = c
      bits[s[i]].add(i + 1, 1)
    end
  else
    l = a.to_i - 1
    r = b.to_i - 1
    res = 0
    ('a'..'z').each do |c|
      t = bits[c].sum(r + 1) - bits[c].sum(l)
      res += 1 if t > 0
    end
    puts res
  end
end
