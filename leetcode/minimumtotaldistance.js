var minimumTotalDistance = function (robot, factory) {
    robot.sort((a, b) => a - b);
    factory.sort((a, b) => a[0] - b[0]);

    const m = robot.length;
    const n = factory.length;

    const memo = Array.from({ length: m }, () => Array(n).fill(-1));

    /**
     * Recursive function to calculate minimum distance
     * @param {number} robotIndex - Current robot index
     * @param {number} factoryIndex - Current factory index
     * @return {number} - Minimum distance for current state
     */
    const calculateMinDistance = (robotIndex, factoryIndex) => {
        if (robotIndex === m) return 0; // All robots assigned
        if (factoryIndex === n) return Infinity; // No more factories available

        if (memo[robotIndex][factoryIndex] !== -1)
            return memo[robotIndex][factoryIndex];

        let answer = calculateMinDistance(robotIndex, factoryIndex + 1);

        let tempDistance = 0;
        for (let k = 0; k < factory[factoryIndex][1]; ++k) {
            if (robotIndex + k >= m) break; // Don't exceed number of robots

            // Add distance for current robot
            tempDistance += Math.abs(
                robot[robotIndex + k] - factory[factoryIndex][0]
            );

            // Compare with solution for remaining robots using next factories
            answer = Math.min(
                answer,
                tempDistance + calculateMinDistance(robotIndex + k + 1, factoryIndex + 1)
            );
        }

        // Store result in memo and return
        memo[robotIndex][factoryIndex] = answer;
        return answer;
    };

    return calculateMinDistance(0, 0);
};