n = gets.to_i
arr = []

n.times do
  s = gets.chomp
  arr.push s
end

ret = 'satisfiable'
h = {}
arr.each do |s|
  f = s[0] == '!'
  t = if f
    s[1..-1]
  else
    s
  end

  if h.key?(t)
    if f != h[t]
      ret = t
      break
    end
  else
    h[t] = f
  end
end

puts ret
