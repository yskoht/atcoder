n, x, m = gets.chomp.split.map(&:to_i)

h = {}
v = []

si = ei = nil

a = x
n.times do |i|
  v.push(a)
  if h.key?(a)
    si = h[a]
    ei = i
    break
  end
  h[a] = i

  a = (a * a) % m
end

if si.nil?
  puts v.sum
else
  v0 = v[0...ei]
  s0 = v0.sum
  v1 = v[si...ei]
  x = n - ei
  y = v1.size

  c = x / y
  d = x % y

  s1 = v1.sum * c
  s2 = v1[0...d].sum

  puts s0 + s1 + s2
end