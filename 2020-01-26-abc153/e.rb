h, n = gets.chomp.split.map(&:to_i)
a = []
b = []
n.times do
  aa, bb = gets.chomp.split.map(&:to_i)
  a.push aa
  b.push bb
end

inf = (1<<29)

t = [inf] * (h + 1)
t[0] = 0
0.upto(h) do |i|
  next if t[i] == inf
  a.zip(b) do |aa, bb|
    j = i + aa
    j = h if j > h
    k = t[i] + bb
    t[j] = k if t[j] > k
  end
end

puts t[h]
