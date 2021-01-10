n, c = gets.chomp.split.map(&:to_i)

h = {}
n.times do |i|
  ai, bi, ci = gets.chomp.split.map(&:to_i)
  h[ai] ||= 0
  h[bi+1] ||= 0
  h[ai] += ci
  h[bi+1] -= ci
end

keys = h.keys.sort
s = 0
t = 0
keys.each_cons(2) do |a, b|
  t += h[a]
  s += [t, c].min * (b - a)
end

puts s
