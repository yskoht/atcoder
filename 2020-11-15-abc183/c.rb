n, k = gets.chomp.split.map(&:to_i)
e = []
n.times do
  e.push gets.chomp.split.map(&:to_i)
end

cnt = 0
(1..n-1).to_a.permutation.to_a.each do |s|
  prev = 0
  t = 0
  s.each do |nxt|
    t += e[prev][nxt]
    prev = nxt
  end
  t += e[prev][0]

  cnt += 1 if t == k
end

puts cnt
